.setcpu "65816"
.segment "CODE"
.org $B175
map_control_0fb175:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
