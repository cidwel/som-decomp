.setcpu "65816"
.segment "CODE"
.org $73DB
map_control_0f73db:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
