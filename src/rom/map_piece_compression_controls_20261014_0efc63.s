.setcpu "65816"
.segment "CODE"
.org $FC63
map_control_0efc63:
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
