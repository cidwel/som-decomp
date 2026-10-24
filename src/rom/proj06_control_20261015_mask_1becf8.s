; Resource06 controls only; no literal payload or M16 fetch-only tail.
.setcpu "65816"
.segment "RODATA"
.org $ECF8
proj06_control_20261015_mask_1becf8:
    .byte (0 << 7) | (0 << 6) | (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1) | (1 << 0)
