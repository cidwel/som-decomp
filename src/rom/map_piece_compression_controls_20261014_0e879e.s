.setcpu "65816"
.segment "CODE"
.org $879E
map_control_0e879e:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
