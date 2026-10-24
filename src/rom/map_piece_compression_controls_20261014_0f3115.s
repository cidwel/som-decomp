.setcpu "65816"
.segment "CODE"
.org $3115
map_control_0f3115:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
