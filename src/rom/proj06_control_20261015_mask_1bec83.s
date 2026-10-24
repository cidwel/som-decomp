; Resource06 controls only; no literal payload or M16 fetch-only tail.
.setcpu "65816"
.segment "RODATA"
.org $EC83
proj06_control_20261015_mask_1bec83:
    .byte (1 << 7) | (0 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (0 << 2) | (1 << 1) | (0 << 0)
