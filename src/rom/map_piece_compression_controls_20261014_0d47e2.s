.setcpu "65816"
.segment "CODE"
.org $47E2
map_control_0d47e2:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
