.setcpu "65816"
.segment "CODE"
.org $AFF1
map_control_0eaff1:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
