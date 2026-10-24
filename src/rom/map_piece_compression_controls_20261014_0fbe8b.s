.setcpu "65816"
.segment "CODE"
.org $BE8B
map_control_0fbe8b:
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E6 ; previous-row copy count
