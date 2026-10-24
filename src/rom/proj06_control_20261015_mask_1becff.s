; Resource06 controls only; no literal payload or M16 fetch-only tail.
.setcpu "65816"
.segment "RODATA"
.org $ECFF
proj06_control_20261015_mask_1becff:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (0 << 4) | (1 << 3) | (0 << 2) | (0 << 1) | (0 << 0)
