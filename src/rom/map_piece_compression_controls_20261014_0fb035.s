.setcpu "65816"
.segment "CODE"
.org $B035
map_control_0fb035:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
