; Resource06 controls only; no literal payload or M16 fetch-only tail.
.setcpu "65816"
.segment "RODATA"
.org $ED63
proj06_control_20261015_mask_1bed63:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (0 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
