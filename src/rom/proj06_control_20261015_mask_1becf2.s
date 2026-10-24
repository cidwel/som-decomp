; Resource06 controls only; no literal payload or M16 fetch-only tail.
.setcpu "65816"
.segment "RODATA"
.org $ECF2
proj06_control_20261015_mask_1becf2:
    .byte (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (0 << 3) | (1 << 2) | (0 << 1) | (0 << 0)
