.setcpu "65816"
.segment "CODE"
.org $7946
map_control_0f7946:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
