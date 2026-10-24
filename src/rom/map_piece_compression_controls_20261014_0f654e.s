.setcpu "65816"
.segment "CODE"
.org $654E
map_control_0f654e:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
