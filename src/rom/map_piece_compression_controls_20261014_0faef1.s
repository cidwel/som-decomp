.setcpu "65816"
.segment "CODE"
.org $AEF1
map_control_0faef1:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $8E ; distance low bit/count
