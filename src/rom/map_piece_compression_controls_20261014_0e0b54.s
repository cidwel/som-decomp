.setcpu "65816"
.segment "CODE"
.org $0B54
map_control_0e0b54:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
