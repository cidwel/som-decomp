.setcpu "65816"
.segment "CODE"
.org $9BEC
map_control_0e9bec:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
