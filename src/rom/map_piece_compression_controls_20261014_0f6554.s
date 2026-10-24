.setcpu "65816"
.segment "CODE"
.org $6554
map_control_0f6554:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
