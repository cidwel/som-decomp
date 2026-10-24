.setcpu "65816"
.segment "CODE"
.org $759D
map_control_0f759d:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
