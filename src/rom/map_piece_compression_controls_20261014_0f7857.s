.setcpu "65816"
.segment "CODE"
.org $7857
map_control_0f7857:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
