.setcpu "65816"
.segment "CODE"
.org $AE41
map_control_0eae41:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
