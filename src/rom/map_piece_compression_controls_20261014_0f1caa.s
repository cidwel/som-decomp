.setcpu "65816"
.segment "CODE"
.org $1CAA
map_control_0f1caa:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
