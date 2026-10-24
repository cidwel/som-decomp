.setcpu "65816"
.segment "CODE"
.org $234C
map_control_0f234c:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
