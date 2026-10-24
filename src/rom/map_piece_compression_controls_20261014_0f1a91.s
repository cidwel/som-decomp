.setcpu "65816"
.segment "CODE"
.org $1A91
map_control_0f1a91:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $70 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $5C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $65 ; row-distance/count
