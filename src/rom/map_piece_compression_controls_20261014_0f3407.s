.setcpu "65816"
.segment "CODE"
.org $3407
map_control_0f3407:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
