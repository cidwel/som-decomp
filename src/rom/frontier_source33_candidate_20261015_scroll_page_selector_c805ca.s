; Planned source-qualified numeric scroll_page_selector; no graphics payload.
; Authority: data/frontier_source33_role_proposal_20261015.json
.setcpu "65816"
.segment "RODATA"
.org $05CA
source33_scroll_page_selector_c805ca:
    .byte (63 & $3F) | (3 << 6)
