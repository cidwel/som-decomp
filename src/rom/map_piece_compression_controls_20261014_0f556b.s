.setcpu "65816"
.segment "CODE"
.org $556B
map_control_0f556b:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
