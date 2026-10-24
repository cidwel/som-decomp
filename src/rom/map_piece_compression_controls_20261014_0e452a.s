.setcpu "65816"
.segment "CODE"
.org $452A
map_control_0e452a:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
