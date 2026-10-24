.setcpu "65816"
.segment "CODE"
.org $2030
map_control_0f2030:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E7 ; previous-row copy count
