.setcpu "65816"
.segment "CODE"
.org $55EC
map_control_0c55ec:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
