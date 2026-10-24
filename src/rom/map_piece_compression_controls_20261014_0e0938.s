.setcpu "65816"
.segment "CODE"
.org $0938
map_control_0e0938:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
