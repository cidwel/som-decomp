.setcpu "65816"
.segment "CODE"
.org $A7DB
map_control_0ea7db:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
