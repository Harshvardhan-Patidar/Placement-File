const express = require("express");
const router = express.Router();
const { users } = require("../data/users.json");

// method: get
// route: /users
router.get("/", (req, res) => {
  res.status(200).json({
    success: true,
    data: users,
  });
});

// route: /users/:id
router.get("/:id", (req, res) => {
  const { id } = req.params;
  const user = users.find((iterate) => iterate.id == id);
  if (!user) {
    return res.status(404).json({
      success: false,
      message: "User not found",
    });
  }
  res.status(200).json({
    success: true,
    user,
  });
});

// route: /subscription-details/:id
router.get("/subscription-details/:id", (req, res) => {
  const id = req.params;
  const user = users.find((iterate) => iterate.id == id);
  if (!user) {
    return res.status(404).json({
      success: false,
      message: "User not found",
    });
  }

  const getdateIndays = (data = "") => {
    let date;
    if (data == "") {
      date = new Date();
    } else {
      date = new Date(data);
    }
    let days = Math.floor(date / (1000 * 60 * 60 * 24));
    return days;
  };

  const subscriptionType = (date) => {
    if (user.subscriptionType == "Basic") date += 90;
    if (user.subscriptionType == "Standard") date += 180;
    if (user.subscriptionType == "Premium") date += 365;
    return date;
  };

  let returnDate = getdateIndays(user.returnDate);
  let currentDate = getdateIndays();
  let subscriptionDate = getdateIndays(user.subscriptionDate);
  let subscriptionExpiration = getdateIndays(subscriptionDate);

  const data = {
    ...user,
    isSubscriptionExpired: subscriptionExpiration <= currentDate,
    daysLeftForExpiration:
      subscriptionExpiration <= currentDate
        ? 0
        : subscriptionExpiration - currentDate,
    fine:
      returnDate < currentDate
        ? subscriptionExpiration <= currentDate
          ? 100
          : 50
        : 0,
  };

  res.status(200).json({
    success: true,
    data,
  });
});

// method: post
// route: /users
router.post("/", (req, res) => {
  const {
    id,
    name,
    surname,
    email,
    issuedBook,
    issuedDate,
    subscriptionType,
    subscriptionDate,
  } = req.body;
  const user = users.find((iterate) => (iterate.id = id));
  if (user) {
    return res.status(404).json({
      success: false,
      message: "User already found",
    });
  }

  users.push({
    id,
    name,
    surname,
    email,
    issuedBook,
    issuedDate,
    subscriptionType,
    subscriptionDate,
  });

  res.status(201).json({
    success: true,
    message: "User added",
  });
});

// method: put
// route: /users/:id (updating the user data)
router.put("/:id", (req, res) => {
  const id = req.params;
  const data = req.body;
  const user = users.find((iterate) => users.id == id);
  if (!user) {
    return res.status(404).json({
      success: false,
      message: "User not found",
    });
  }

  const updateUserData = users.map((iterate) => {
    if (iterate.id == id) {
      return {
        ...iterate,
        ...data,
      };
    }
    return iterate;
  });

  res.status(200).json({
    success: true,
    message: "Data updated",
  });
});

// method: delete
// route: /users/:id
router.delete("/:id", (req, res) => {
  const id = req.params;
  const user = users.find((iterate) => iterate.id == id);
  if (!user) {
    return res.status(404).json({
      success: true,
      message: "User not found",
    });
  }

  const index = users.indexOf(user);
  users.splice(index, 1);
  res.status(200).json({
    success: true,
    message: "User deleted",
  });
});

module.exports = router;
