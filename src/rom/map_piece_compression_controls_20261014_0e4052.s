.setcpu "65816"
.segment "CODE"
.org $4052
map_control_0e4052:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
