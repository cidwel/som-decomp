.setcpu "65816"
.segment "CODE"
.org $8629
map_control_0c8629:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
