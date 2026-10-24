.setcpu "65816"
.segment "CODE"
.org $AFF5
map_control_0eaff5:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
