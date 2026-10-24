.setcpu "65816"
.segment "CODE"
.org $308C
map_control_0d308c:
    .byte $E7 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
