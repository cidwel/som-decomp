.setcpu "65816"
.segment "CODE"
.org $329F
map_control_0e329f:
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
