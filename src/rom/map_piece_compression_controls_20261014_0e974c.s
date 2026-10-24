.setcpu "65816"
.segment "CODE"
.org $974C
map_control_0e974c:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
