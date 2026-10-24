.setcpu "65816"
.segment "CODE"
.org $2B52
map_control_0f2b52:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
