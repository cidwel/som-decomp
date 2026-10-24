.setcpu "65816"
.segment "CODE"
.org $1A6B
map_control_0f1a6b:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
