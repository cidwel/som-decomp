.setcpu "65816"
.segment "CODE"
.org $0FB4
map_control_0e0fb4:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
