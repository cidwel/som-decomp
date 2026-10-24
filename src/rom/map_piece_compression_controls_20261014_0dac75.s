.setcpu "65816"
.segment "CODE"
.org $AC75
map_control_0dac75:
    .byte $E5 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $36 ; distance low bit/count
