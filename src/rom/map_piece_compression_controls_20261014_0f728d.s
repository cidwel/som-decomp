.setcpu "65816"
.segment "CODE"
.org $728D
map_control_0f728d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
