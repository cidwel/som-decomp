.setcpu "65816"
.segment "CODE"
.org $766D
map_control_0c766d:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E2 ; previous-row copy count
