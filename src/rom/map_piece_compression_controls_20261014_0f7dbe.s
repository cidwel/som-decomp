.setcpu "65816"
.segment "CODE"
.org $7DBE
map_control_0f7dbe:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
