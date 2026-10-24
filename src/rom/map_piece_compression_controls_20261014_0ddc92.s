.setcpu "65816"
.segment "CODE"
.org $DC92
map_control_0ddc92:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
