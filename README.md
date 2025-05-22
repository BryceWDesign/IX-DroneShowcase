# 🛰 IX-DroneShowcase

This repository documents the complete design showcase for an IX-powered drone platform engineered for space, remote, and off-grid environments. The project is non-executable, intended as a full-system conceptual architecture and technical demonstration for outreach, review, and potential collaboration.

---

## 🧠 Mission Overview

The IX-DroneShowcase represents a next-generation aerial and zero-G drone platform that fuses real-time environmental sensing, adaptive energy harvesting, and immersive VR/AI control into a single high-reliability system designed for:

- Orbital utility tasks (inspection, EVA support, internal spacecraft nav)
- Remote scientific missions (high atmosphere, disaster zones, deep field)
- Fully autonomous or operator-assisted deployment in extreme conditions

---

## ⚡ Energy Harvesting Strategy

The drone system uses a tri-source energy harvesting strategy:

- RF scavenging (urban/cellular, or spacecraft EM fields)
- Thermoelectric harvesting (TEGs on hot/cold shell delta)
- Piezoelectric from vibration/motion

All three operate in parallel using adaptive real-time source prioritization. Energy is stored in a hybrid bank:

- Supercapacitor array (for burst power and startup)
- Solid-state battery (for long-duration operations)

---

## ✨ Autonomy & Control Stack

- Primary flight controller: Pixhawk 6C running PX4
- Optional override via immersive VR control system (stereo cam + haptic input)
- Fully autonomous logic for obstacle nav, energy awareness, and return protocols
- Companion compute (Jetson Nano or RPi) for AI tasks, vision, and telemetry

---

## 📡 Telemetry and Sensing

Sensors include:

- IMU + GPS (Earth mode)
- LIDAR + stereo camera (SLAM & mapping)
- PressureX module for ambient pressure feedback
- Environmental telemetry: temperature, radiation, energy yield per harvester

---

## 🛠 Repository Structure

    /IX-DroneShowcase
    ├── README.md                ← This file
    ├── energy/
    │   ├── energy_harvester.sch
    │   └── energy_harvester.kicad_pcb
    ├── control/
    │   └── flight_controller_config.px4
    ├── pressurex/
    │   └── pressurex_module.sch
    └── docs/
        └── IX_drone_summary.pdf

More files added as components are detailed.

---

## 🧬 License

This repository is licensed under the MIT License (see LICENSE.md). It permits free use, modification, and distribution, including commercial use, provided proper attribution is given to the original author.

---
IX-DroneShowcase is a vision-first technology demonstrator. The goal is to push the boundary of what’s possible at the intersection of adaptive autonomy, sustainable energy systems, and human-machine integration.
