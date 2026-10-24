.setcpu "65816"
.segment "CODE"
.org $E737
map_control_0de737:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
