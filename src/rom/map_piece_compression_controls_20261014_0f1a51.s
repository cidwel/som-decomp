.setcpu "65816"
.segment "CODE"
.org $1A51
map_control_0f1a51:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
