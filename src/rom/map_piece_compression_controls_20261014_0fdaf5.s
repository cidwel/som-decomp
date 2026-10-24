.setcpu "65816"
.segment "CODE"
.org $DAF5
map_control_0fdaf5:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
