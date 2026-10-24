.setcpu "65816"
.segment "CODE"
.org $18DB
map_control_0c18db:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
