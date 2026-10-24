.setcpu "65816"
.segment "CODE"
.org $6E54
map_control_0d6e54:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
