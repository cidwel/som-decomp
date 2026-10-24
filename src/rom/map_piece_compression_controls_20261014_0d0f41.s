.setcpu "65816"
.segment "CODE"
.org $0F41
map_control_0d0f41:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
