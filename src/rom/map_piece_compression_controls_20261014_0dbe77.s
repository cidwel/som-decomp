.setcpu "65816"
.segment "CODE"
.org $BE77
map_control_0dbe77:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
