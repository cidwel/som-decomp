.setcpu "65816"
.segment "CODE"
.org $169F
map_control_0e169f:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
